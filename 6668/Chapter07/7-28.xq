declare namespace my = "http://brians.org/synsets"; 
declare function my:guess($answerId as xs:decimal, $guessId as xs:decimal) { 
  if (collection("steps.dbxml")//*[@id = $guessId]//*[@id = $answerId]) 
  then true() 
  else false() 
}; 

my:guess(56056, 19),   (: policeman, person :) 
my:guess(56056, 53188)   (: policeman, cook :) 

