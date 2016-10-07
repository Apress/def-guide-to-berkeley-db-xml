<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$ucontext = $mgr->createUpdateContext(); 
$indexspec = $container->getIndexSpecification(); 
$indexspec->deleteIndex("", "person", "node-element-equality-string"); 
$indexspec->addIndex("", "person", "node-attribute-equality-string"); 
$container->setIndexSpecification($indexspec, $ucontext); 

