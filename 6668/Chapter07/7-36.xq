for $person in collection("people.dbxml")/person 
for $office in $person/phone/office 
for $home in $person/phone/home 
where $office = "612-555-9901" or $home = "612-555-9901" 
return $person 

