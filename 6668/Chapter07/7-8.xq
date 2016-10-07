let $baseballs := collection("synsets.dbxml")/Synset[Word="baseball"]/Id 
for $synset in collection("synsets.dbxml")/Synset 
where $synset/Pointers/Hypernym = $baseballs 
return $synset/Id 

