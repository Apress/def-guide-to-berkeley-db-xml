<?php
$mgr = new XmlManager(); 
$query = "collection('test.dbxml')/person[name='Fred']"; 
$subquery = "/person/phone"; 
$container = $mgr->openContainer("test.dbxml"); 
$qcontext = $mgr->createQueryContext(); 
$phoneqcontext = $mgr->createQueryContext(); 
$results = $mgr->query($query, $qcontext); 
$phonequery = $mgr->prepare($subquery, $phoneqcontext); 
while ($results->hasNext()) { 
  $value = $results->next(); 
  $phoneresults = $phonequery->execute($value, $phoneqcontext); 
  while ($phoneresults->hasNext()) { 
    $phonevalue = $phoneresults->next(); 
    print $phonevalue->asString() . "\n"; 
  } 
} 

