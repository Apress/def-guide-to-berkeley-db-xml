declare namespace my = "http://brians.org/temperature"; 
declare function my:celsius-to-fahrenheit ($celsius as xs:decimal) as xs:decimal { 
  ($celsius + 32) * (9 div 5) 
}; 
my:celsius-to-fahrenheit(15) 

