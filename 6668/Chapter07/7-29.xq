for $step in collection("steps.dbxml")//*[@id = "24"]//* 
where matches($step/@name, "an$") 
return $step/@name/string() 

