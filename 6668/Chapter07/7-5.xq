declare namespace people = "urn:something"; 
declare variable $name as xs:string external; 
declare function people:age-ok($age) { 
if (21 < $age and $age < 100) 
then true() 
else false() 
}; 
(: Here is a comment. :) 
<people> 
{ 
  for $person in collection("people.dbxml")/person 
  where people:age-ok($person/age/number()) and $person/name/*/string() = $name 
  order by $person/name/last 
  return 
  <person> 
    <name>{$person/name/*}</name> 
    <age>{$person/age/string()}</age> 
    </person> 
} 
</people> 

