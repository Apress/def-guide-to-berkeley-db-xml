<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$container->addIndex("", "person", "node-element-equality-string"); 

