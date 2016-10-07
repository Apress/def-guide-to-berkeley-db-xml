<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$ucontext = $mgr->createUpdateContext(); 
$newcontent = "<person><name>Bob</name></person>"; 
$document = $container->getDocument("file12.xml"); 
$document->setContent("<person><name>Bob2</name></person>"); 
$container->updateDocument($document, $ucontext); 

