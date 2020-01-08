// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file XMLProfilesExamplePubSubMain.cpp
 * This file acts as a main entry point to the application.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include "XMLProfilesExamplePublisher.h"
#include "XMLProfilesExampleSubscriber.h"


#include <fastrtps/Domain.h>
#include <fastrtps/xmlparser/XMLProfileParser.h>

using namespace eprosima;
using namespace eprosima::fastrtps;

int main(int argc, char** argv)
{
	int type = 0;

	if (argc == 2)
	{
		if (strcmp(argv[1], "publisher") == 0)
		{
			type = 1;
		}
		else if (strcmp(argv[1], "subscriber") == 0)
		{
			type = 2;
		}
	}

	if (type==0)
	{
		std::cout << "Error: Incorrect arguments." << std::endl;
        	std::cout << "Usage: " << std::endl << std::endl;
		std::cout << argv[0] << " publisher|subscriber" << std::endl << std::endl;
		return 0;
	}

	std::cout << "Starting " << std::endl;

	// Load an XML file with predefined profiles for publisher and subscriber
	xmlparser::XMLProfileParser::loadXMLFile("XMLProfilesExample.xml");

	// Register the type being used

	switch(type)
	{
		case 1:
		{
			XMLProfilesExamplePublisher mypub;
			if (mypub.init())
			{
				mypub.run();
			}
			break;
		}
		case 2:
		{
			XMLProfilesExampleSubscriber mysub;
			if (mysub.init())
			{
				mysub.run();
			}
			break;
		}
	}

	return 0;
}
