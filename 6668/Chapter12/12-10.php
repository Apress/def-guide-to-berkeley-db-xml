<?php
$mgr = new XmlManager(); 
$query = "collection('test.dbxml')//Word"; 
$container = $mgr->openContainer("test.dbxml"); 
$qcontext = $mgr->createQueryContext(); 
$results = $mgr->query($query, $qcontext); 
while ($results->hasNext()) { 
  $value = $results->next(); 
  $document = $value->asDocument(); 
  $name     = $document->getName(); 
  $content  = $value->asString(); 
  print $name . ": " . $content . "\n"; 
} 

