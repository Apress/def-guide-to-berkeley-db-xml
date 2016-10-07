<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$ucontext = $mgr->createUpdateContext(); 
$content = "<person><name>Bob</name></person>"; 
$container->putDocument("", $content, $ucontext, DBXML_GEN_NAME); 

