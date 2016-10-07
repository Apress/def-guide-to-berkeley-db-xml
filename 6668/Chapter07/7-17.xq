let $areacode := "612" 
let $match := concat("^", $areacode, "[-\\.]\\d{3}[-\\.]\\d{4}$") 
return matches("612.423.1124", $match) 

