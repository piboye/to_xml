all: test_to_xml

test_to_xml: test_to_xml.cpp to_xml.h
	g++ $< -o $@


to_xml.h: to_xml.h.pump
	./pump.py $^

clean:
	rm -rf *.o test_to_xml
