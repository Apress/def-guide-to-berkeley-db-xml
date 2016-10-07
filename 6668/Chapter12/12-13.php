<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$ucontext = $mgr->createUpdateContext(); 
$qcontext = $mgr->createQueryContext(); 
$content = "<person><name>Bob</name></person>"; 
$container->putDocument("", $content, $ucontext, DBXML_GEN_NAME); 
$results = $mgr->query("collection('test.dbxml')/person[name='Bob']", $qcontext); 
while ($results->hasNext()) { 
  $value = $results->next(); 
  $document = $value->asDocument(); 
  print "Deleting document: " . $document->getName() . "\n"; 
  $container->deleteDocument($document, $ucontext); 
} 

