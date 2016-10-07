for $person in collection("people.dbxml")/person 
for $phone in $person/phone/*/string() 
where $phone = "612-555-9901" 
return $person 

