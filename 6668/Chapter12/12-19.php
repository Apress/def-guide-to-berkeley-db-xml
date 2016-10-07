<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$ucontext = $mgr->createUpdateContext(); 
$uri = "http://brians.org/metadata/"; 
$metaname = "createdOn"; 
$metavalue = new XmlValue(); 
$document = $container->getDocument("file14.xml"); 
$metavalue = $document->getMetaData($uri, $metaname); 
print "file14.xml, created on " . $metavalue->asString() . "\n"; 

