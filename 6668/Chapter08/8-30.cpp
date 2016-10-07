XmlDocument doc = container.getDocument("doc12"); 
XmlEventReader &reader = doc.getContentAsEventReader(); 
while (reader.hasNext()) { 
  XmlEventType type = reader.next(); 
  if (type == StartElement) { 
    cout << "Event is StartElement for node: " << 
    reader.getLocalName(); 
  } 
  reader.close(); // release resources 
} 

