for $person in collection("people.dbxml")//person[name/first = "Jim"] 
for $known in collection("people.dbxml")//person[name/last = "Brown"] 
where $person is $known 
return $person 

