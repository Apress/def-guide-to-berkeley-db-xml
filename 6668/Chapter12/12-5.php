<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$xmlinput = $mgr->createLocalFileInputStream("file14.xml"); 
$container->putDocument("file14", $xmlinput); 

