declare namespace my = "http://brians.org/temperature"; 
declare function my:binary ($dec as xs:decimal) { 
  if ($dec eq 0 or $dec eq 1) 
    then $dec 
  else 
    let $m := xs:integer($dec div 2) 
    let $j := $dec mod 2 
    let $D := my:binary($m) 
    return concat(string($D), string($j)) 
}; 

