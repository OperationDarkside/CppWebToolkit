#pragma once
#include "HtmlAttribute.h"
#include "HtmlDataAttribute.h"


namespace dnc{
	namespace Web{
		class HtmlElement: public Object{
		public:
			HtmlElement();
			~HtmlElement();

			/**
			Adds a new Element to this instance's children

			@param element HtmlElement to add
			*/
			void AddElement(HtmlElement* element);

			/**
			Returns the Html String of this instance including its children

			@param element HtmlElement to add
			*/
			virtual String toHtml();

			// AccessKey
			String& AccessKey();
			void AccessKey(String& value);
			// Class
			String& Class();
			void Class(String& value);
			// ContentEditable
			bool ContentEditable();
			void ContentEditable(bool value);
			// ContextMenu
			String& ContextMenu();
			void ContextMenu(String& value);
			// Data*
			void AddDataAttribute(String& name, String& value);
			void AddDataAttribute(HtmlDataAttribute& attr);
			HtmlDataAttribute& GetDataAttribute(String& name);
			// Dir
			String& Dir();
			void Dir(String& value);
			// Draggable
			String& Draggable();
			void Draggable(String& value);
			// Dropzone
			String& Dropzone();
			void Dropzone(String& value);
			// Hidden
			bool Hidden();
			void Hidden(bool value);
			// ID
			String& ID();
			void ID(String& value);
			// Lang
			String& Lang();
			void Lang(String& value);
			// Spellcheck
			bool Spellcheck();
			void Spellcheck(bool value);
			// Style
			String& Style();
			void Style(String& value);
			// TabIndex
			int TabIndex();
			void TabIndex(int value);
			// Title
			String& Title();
			void Title(String& value);
			// Translate
			bool Translate();
			void Translate(bool value);

			std::string toString();
			std::string getTypeString();
		protected:
			/*Open Tag*/
			String html_part1;
			/*Close Tag*/
			String html_part2;
			/*Inner Text*/
			String innerText;
			/*Sub-Elements*/
			std::vector<HtmlElement*> children;

			//Attributes
			/* true/false are represented as integer:
				0 == not set
				1 == true
				2 == false
			*/
			String accessKey;
			String _class;
			int contentEditable = 0;
			String contextMenu;
			std::vector<HtmlDataAttribute> dataAttributes;
			String dir;
			String draggable;
			String dropzone;
			int hidden = 0;
			String id;
			String lang;
			int spellcheck = 0;
			String style;
			int tabIndex = 0;
			String title;
			int translate = 0;

			virtual String getAttributeString();
		};
	}
}