declare namespace my = "http://brians.org/synsets"; 
declare function my:hypernyms ($synset) { 
  let $hyp := $synset/Pointers/Hypernym[1]/string() 
  return 
  if (empty($hyp)) 
    then $synset/Id/string() 
  else 
    let $next := my:hypernyms(collection("synsets.dbxml")/Synset[Id = $hyp]) 
    return ($synset/Id/string(), $next) 
  }; 
  declare function my:tree ($idlist) { 
    if (empty($idlist)) 
      then () 
    else 
      element step { 
        attribute id {$idlist[1]}, 
        attribute name {collection("synsets.dbxml")/Synset[Id = $idlist[1]]/Word[1]}, 
        my:tree(remove($idlist, 1)) 
    } 
}; 

let $list := my:hypernyms((collection("synsets.dbxml")/Synset[Word="flan"])[1]) 
return my:tree(reverse($list)) 

