for $x in collection("people.dbxml")/person/name/first 
for $y in collection("synsets.dbxml")/Synset/Word 
where contains($y, $x) 
return (string($x), "=>", string($y)) 

