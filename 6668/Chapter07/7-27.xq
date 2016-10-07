declare namespace my = "http://brians.org/synsets"; 
declare variable $rand as xs:decimal external; 
declare function my:random-synset () { 
  let $count := 250000   (: the number of records for our set :) 
  let $synset := (collection("steps.dbxml")//*[@id="9"]//*)[($count * $rand) cast as 
  xs:integer] 
  return ($synset/@id/string(), $synset/@name/string()) 
}; 

my:random-synset() 

