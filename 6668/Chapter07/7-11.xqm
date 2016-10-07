module namespace temp = "http://brians.org/temperature"; 
declare function temp:celsius-to-fahrenheit ($celsius as xs:decimal) { 
  ($celsius + 32) * (9 div 5) 
}; 

