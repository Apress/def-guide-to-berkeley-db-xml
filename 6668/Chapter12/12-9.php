<?php
$mgr = new XmlManager(); 
$query = "collection('test.dbxml')/person[name='Jim']"; 
$container = $mgr->openContainer("test.dbxml"); 
$qcontext = $mgr->createQueryContext(); 
$qcontext->setEvaluationType(XmlQueryContext_Lazy); 
$results = $mgr->query($query, $qcontext); 

