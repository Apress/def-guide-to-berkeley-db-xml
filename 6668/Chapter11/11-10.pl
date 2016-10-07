use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $query = "collection('test.dbxml')//Word";

my $container = $mgr->openContainer("test.dbxml");
my $qcontext = $mgr->createQueryContext();
my $results = $mgr->query($query, $qcontext);

my $value = new XmlValue();
while ($results->next($value)) {
    my $document = $value->asDocument();
    my $name     = $document->getName();
    my $content  = $value->asString();
    print name . ": " . $content . "\n";
}

