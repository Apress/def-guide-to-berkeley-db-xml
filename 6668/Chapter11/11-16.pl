use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $container = $mgr->openContainer("test.dbxml");
my $ucontext = $mgr->createUpdateContext();

my $indexspec = $container->getIndexSpecification();
$indexspec->deleteIndex("", "person", "node-element-equality-string");
$indexspec->addIndex("", "person", "node-attribute-equality-string");
$container->setIndexSpecification($indexspec, $ucontext);


