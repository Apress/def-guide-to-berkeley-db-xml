declare namespace my = "http://brians.org/range"; 
declare function my:in-range ($myLon as xs:decimal, $myLat as xs:decimal, $range
     as xs:decimal) { 
  for $place in collection("coord.dbxml")/place 
    where ($place/latitude > ($myLat - $range) and $place/latitude < ($myLat + 
        $range)) 
    and ($place/longitude > ($myLon - $range) and $place/longitude < ($myLon + 
        $range)) 
  return $place/name/text() 
}; 

my:in-range (-111.651862515931, 40.00652821419428, 2) 

