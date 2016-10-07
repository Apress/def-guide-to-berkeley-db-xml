for $person in collection("people.dbxml")/person 
where starts-with($person/phone, "612") 
return $person 

