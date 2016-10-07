for $baseball in collection("synsets.dbxml")/Synset[Word="baseball"]/Id, 
    $synset in collection("synsets.dbxml")/Synset 
where $synset/Pointers/Hypernym = $baseball/Id 
return $synset/Id 

