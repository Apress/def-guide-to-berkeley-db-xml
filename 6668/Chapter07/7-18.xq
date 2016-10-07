for $document in collection("people.dbxml")/* 
where $document[dbxml:metadata("dbxml:name") = "person1"] 
return $document 

