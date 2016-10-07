<?php
$mgr = new XmlManager(); 
$query = "collection('test.dbxml')/person[name='Jim']"; 
$container = $mgr->openContainer("test.dbxml"); 
$results = $mgr->query($query, $qcontext); 

