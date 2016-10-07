declare variable $phone xs:string external; 
for $person in collection("people.dbxml")/person 
where $person/phone eq $phone 
return concat($person/name/first, "'s ", $person/phone[string() = $phone]/@loc, " phone is: ", $phone) 

