<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$qcontext = $mgr->createQueryContext(); 
$ucontext = $mgr->createUpdateContext(); 
$modify = $mgr->createModify(); 
$queryexp = $mgr->prepare("/person/name", $qcontext); 
$modify->addAppendStep($queryexp, XmlModify_Attribute, "type", "given"); 
$document = $container->getDocument("file14"); 
$doc_value = new XmlValue($document); 
$modify->execute($doc_value, $qcontext, $ucontext); 

