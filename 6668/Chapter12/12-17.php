<?php
$mgr = new XmlManager(); 
$container = $mgr->openContainer("test.dbxml"); 
$qcontext = $mgr->createQueryContext(); 
$indexlookup = $mgr->createIndexLookup($container, "", "person", 
"node-element-equality-string"); 
$results = $indexlookup->execute($qcontext); 
while ($results->hasNext()) { 
  $value = $results->next(); 
  my $document = $value->asDocument(); 
  print $document->getName() . ": " . $document->getContent(); 
} 

