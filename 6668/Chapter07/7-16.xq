for $person in collection("people.dbxml")/person 
where some $phone in $person/phone satisfies (matches($phone, "^612")) 
return $person 

