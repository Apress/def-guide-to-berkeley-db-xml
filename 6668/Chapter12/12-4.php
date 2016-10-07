<?php
$mgr = new XmlManager(); 
$mgr->renameContainer("test.dbxml", "old-test.dbxml"); 
$mgr->removeContainer("backup-test.dbxml"); 

