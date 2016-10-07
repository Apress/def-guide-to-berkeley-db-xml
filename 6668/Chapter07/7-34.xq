declare namespace my = "http://brians.org/range"; 
declare function my:in-range ($myLon as xs:decimal, $myLat as xs:decimal, $range as xs:decimal) { 
  for $place in collection("coord.dbxml")/place 
  where ($place/latitude > ($myLat - $range) and $place/latitude < ($myLat + $range)) 
    and ($place/longitude > ($myLon - $range) and $place/longitude < ($myLon + $range)) 
  return $place/name/text() 
}; 

let $placesCloseToHome := my:in-range (-111.651862515931, 40.00652821419428, 12) 
let $placesCloseToJim := my:in-range (-93.49764084020113, 45.01312134030998, 12)
return $placesCloseToHome union $placesCloseToJim 

