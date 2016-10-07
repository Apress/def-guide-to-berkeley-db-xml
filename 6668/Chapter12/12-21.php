<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$qcontext = $mgr->createQueryContext(); 
$ucontext = $mgr->createUpdateContext(); 
$modify = $mgr->createModify(); 
$queryexp = $mgr->prepare("/person/name", $qcontext); 
$modify->addAppendStep($queryexp, XmlModify_Attribute, "type", "given"); 
$results = $mgr->query("collection('test.dbxml')/person[name='Bill']", $qcontext); 
$modify->execute($results, $qcontext, $ucontext); 

