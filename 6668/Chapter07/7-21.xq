declare namespace my = "http://brians.org/synsets"; 
declare function my:hypernyms ($synset) { 
  let $hyp := $synset/Pointers/Hypernym[1]/string() 
  return 
  if (empty($hyp)) 
    then ($synset/Word)[1]/string() 
    else 
      let $next := my:hypernyms(collection("synsets.dbxml")/Synset[Id = $hyp]) 
    return concat($next, " => ", $synset/Word[1]) 
  }; 

my:hypernyms((collection("synsets.dbxml")/Synset[Word="banana"])[1]) 

