<?php
$mgr = new XmlManager(); 
$query = "collection()/person[name='Bob']"; 
$container = $mgr->openContainer("test.dbxml"); 
$qcontext = $mgr->createQueryContext(); 
$qcontext->setDefaultCollection("test.dbxml"); 
$query_exp = $mgr->prepare($query, $qcontext); 
$results = $query_exp->execute($qcontext); 

