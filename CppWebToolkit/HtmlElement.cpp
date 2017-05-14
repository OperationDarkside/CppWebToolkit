#include "HtmlElement.h"


namespace dnc{
	namespace Web{

		HtmlElement::HtmlElement(){}

		HtmlElement::~HtmlElement(){}

		void HtmlElement::AddElement(HtmlElement* element){
			this->children.push_back(element);
		}

		String HtmlElement::toHtml(){
			size_t len_SubElements = 0;
			String str;
			String strAttr;

			// Add HtmlAttributes
			strAttr = getAttributeString();
			this->html_part1.insert(this->html_part1.length() - 1, &strAttr);

			// Add Sub-HtmlElements
			str += this->html_part1;

			// Add inner text
			str += this->innerText;

			len_SubElements = this->children.size();
			for(size_t i = 0; i < len_SubElements; i++){
				HtmlElement* ele = this->children[i];
				str += ele->toHtml();
			}

			str += this->html_part2;

			return str;
		}

		String & HtmlElement::AccessKey(){
			return this->accessKey;
		}

		void HtmlElement::AccessKey(String & value){
			this->accessKey = value;
		}

		String & HtmlElement::Class(){
			return this->_class;
		}

		void HtmlElement::Class(String & value){
			this->_class = value;
		}

		bool HtmlElement::ContentEditable(){
			return (this->contentEditable == 1 ? true : false);
		}

		void HtmlElement::ContentEditable(bool value){
			this->contentEditable = value ? 1 : 2;
		}

		String & HtmlElement::ContextMenu(){
			return this->contextMenu;
		}

		void HtmlElement::ContextMenu(String & value){
			this->contextMenu = value;
		}

		void HtmlElement::AddDataAttribute(String & name, String & value){
			this->dataAttributes.push_back(HtmlDataAttribute(name, value));
		}

		void HtmlElement::AddDataAttribute(HtmlDataAttribute & attr){
			this->dataAttributes.push_back(attr);
		}

		HtmlDataAttribute & HtmlElement::GetDataAttribute(String & name){
			size_t len = 0;
			HtmlDataAttribute attr;

			len = this->dataAttributes.size();

			for(size_t i = 0; i < len; i++){
				attr = this->dataAttributes[i];
				if(attr.Name() == name){
					return attr;
				}
			}
		}

		String & HtmlElement::Dir(){
			return this->dir;
		}

		void HtmlElement::Dir(String & value){
			this->dir = value;
		}

		String & HtmlElement::Draggable(){
			return this->draggable;
		}

		void HtmlElement::Draggable(String & value){
			this->draggable = value;
		}

		String & HtmlElement::Dropzone(){
			return this->dropzone;
		}

		void HtmlElement::Dropzone(String & value){
			this->dropzone = value;
		}

		bool HtmlElement::Hidden(){
			return (this->hidden == 1 ? true : false);
		}

		void HtmlElement::Hidden(bool value){
			this->hidden = value ? 1 : 2;
		}

		String & HtmlElement::ID(){
			return this->id;
		}

		void HtmlElement::ID(String & value){
			this->id = value;
		}

		String & HtmlElement::Lang(){
			return this->lang;
		}

		void HtmlElement::Lang(String & value){
			this->lang = value;
		}

		bool HtmlElement::Spellcheck(){
			return (this->spellcheck == 1 ? true : false);
		}

		void HtmlElement::Spellcheck(bool value){
			this->spellcheck = value ? 1 : 2;
		}

		String & HtmlElement::Style(){
			return this->style;
		}

		void HtmlElement::Style(String & value){
			this->style = value;
		}

		int HtmlElement::TabIndex(){
			return this->tabIndex;
		}

		void HtmlElement::TabIndex(int value){
			if(value > 0){
				this->tabIndex = value;
			} else{
				throw "TabIndex too small";
			}
		}

		String & HtmlElement::Title(){
			return this->title;
		}

		void HtmlElement::Title(String & value){
			this->title = value;
		}

		bool HtmlElement::Translate(){
			return (this->translate == 1 ? true : false);
		}

		void HtmlElement::Translate(bool value){
			this->translate = value ? 1 : 2;
		}

		std::string HtmlElement::toString(){
			return std::string("System.Web.HtmlElement");
		}

		std::string HtmlElement::getTypeString(){
			return std::string("HtmlElement");
		}

		String HtmlElement::getAttributeString(){
			String res;

			// AccessKey
			if(this->accessKey != ""){
				res = " accesskey=\"" + this->accessKey + "\" ";
			}
			//Class
			if(this->_class != ""){
				res += "class=\"" + this->_class + "\" ";
			}
			//ContentEditable
			if(this->contentEditable != 0){
				res += "contenteditable=\"" + std::to_string(this->contentEditable == 1 ? true : false) + "\" ";
			}
			//ContextMenu
			if(this->contextMenu != ""){
				res += "contextmenu=\"" + this->contextMenu + "\" ";
			}
			// Data-* Attributes
			for each (HtmlDataAttribute attr in this->dataAttributes){
				res += "data-" + attr.Name() + "=\"" + attr.Value() + "\" ";
			}
			// Dir
			if(this->dir != ""){
				res += "dir=\"" + this->dir + "\" ";
			}
			// Draggable
			if(this->draggable != ""){
				res += "draggable=\"" + this->draggable + "\" ";
			}
			// Dropzone
			if(this->dropzone != ""){
				res += "dropzone=\"" + this->dropzone + "\" ";
			}
			// Hidden
			if(this->hidden == 1){
				res += "hidden ";
			}
			// ID
			if(this->id != ""){
				res += "id=\"" + this->id + "\" ";
			}
			//Lang
			if(this->lang != ""){
				res += "lang=\"" + this->lang + "\" ";
			}
			// Spellcheck
			if(this->spellcheck != 0){
				res += "spellcheck=\"" + std::to_string(this->spellcheck == 1 ? true : false) + "\" ";
			}
			// Style
			if(this->style != ""){
				res += "style=\"" + this->style + "\" ";
			}
			// TabIndex
			if(this->tabIndex > 0){
				res += "tabindex=\"" + std::to_string(this->tabIndex) + "\" ";
			}
			// Title
			if(this->title != ""){
				res += "title=\"" + this->title + "\" ";
			}
			// Translate
			if(this->translate != 0){
				res += "translate=\"" + std::string(this->translate == 1 ? "yes" : "no") + "\" ";
			}

			return res;
		}
	}
}