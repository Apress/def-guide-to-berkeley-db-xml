<?php
$mgr = new XmlManager(); 
$query = "collection('test.dbxml')/people:person[name='\$name']"; 
$container = $mgr->openContainer("test.dbxml"); 
$qcontext = $mgr->createQueryContext(); 
$qcontext->setNamespace("people", "http://brians.org/people/"); 
$qcontext->setVariableValue("name", new XmlValue("Bob")); 
$query_exp = $mgr->prepare($query, $qcontext); 
$results = $query_exp->execute($qcontext); 

