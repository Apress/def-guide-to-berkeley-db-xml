use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $query = "collection('test.dbxml')/people:person[name='\$name']";

my $container = $mgr->openContainer("test.dbxml");
my $qcontext = $mgr->createQueryContext();
$qcontext->setNamespace("people", "http://brians.org/people/");
$qcontext->setVariableValue("name", new XmlValue("Bob"));

my $query_exp = $mgr->prepare($query, $qcontext);
my $results = $query_exp->execute($qcontext);

