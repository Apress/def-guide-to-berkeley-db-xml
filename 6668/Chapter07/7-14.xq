for $person in collection("people.dbxml")/person 
for $phone in $person/phone 
where starts-with($phone, "612") 
return $person 

