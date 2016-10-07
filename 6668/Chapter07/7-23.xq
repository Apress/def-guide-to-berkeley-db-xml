declare namespace my = "http://brians.org/synsets"; 
declare function my:steps ($synset) as element() { 
  let $hyp := $synset/Pointers/Hypernym[1]/string() 
  return 
  if (empty($hyp)) 
    then element step { attribute name {($synset/Word)[1]} } 
  else 
    let $next := my:steps(collection("synsets.dbxml")/Synset[Id = $hyp]) 
    return element step { 
      attribute name { $synset/Word[1] }, 
      $next 
    } 
}; 

my:steps((collection("synsets.dbxml")/Synset[Word="banana"])[1]) 

