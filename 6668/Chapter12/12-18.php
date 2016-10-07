<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$uri = "http://brians.org/metadata/"; 
$metaname = "createdOn"; 
$metavalue = new XmlValue(XmlValue_DATE_TIME, "2006-02-05T05:23:14"); 
$document = $container->getDocument("file14.xml"); 
$document->setMetaData($uri, $metaname, $metavalue); 
$container->updateDocument($document); 

