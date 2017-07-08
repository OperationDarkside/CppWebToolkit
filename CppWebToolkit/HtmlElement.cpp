#include "HtmlElement.h"
#include "Meta.h"


namespace dnc{
	namespace Web{

		HtmlElement::HtmlElement(){}

		//HtmlElement::HtmlElement(const HtmlElement & ele) {}

		//HtmlElement::HtmlElement(HtmlElement && ele) {}

		HtmlElement::~HtmlElement(){}

		/*
		template <typename T>
		void HtmlElement::AddElement(T& element){
			//std::unique_ptr<HtmlElement> temp(new HtmlElement(element));
			HtmlElement* ele = static_cast<HtmlElement*>(element);

			if(ele != nullptr) {
				this->children.Add(std::make_shared<T>(element));
			} else {
				throw "Not a HtmlElement!";
			}
			//this->children.Add(&element);
			//this->ch.push_back(std::make_unique<String>());
		}
		*/

		String HtmlElement::toHtml(){
			size_t len_SubElements = 0;
			String str;
			String strAttr;

			// Add HtmlAttributes
			strAttr = this->getAttributeString();
			this->html_part1.insert(this->html_part1.length() - 1, &strAttr);

			// Add Sub-HtmlElements
			str += this->html_part1;

			// Add inner text
			str += this->innerText;
			
			len_SubElements = this->children.Count();
			for(size_t i = 0; i < len_SubElements; i++){
				HtmlElement* ele = this->children[i].get();
				str += ele->toHtml();

				Meta* mt = dynamic_cast<Meta*>(ele);
				int intel = 0;
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
			this->dataAttributes.Add(HtmlDataAttribute(name, value));
		}

		void HtmlElement::AddDataAttribute(HtmlDataAttribute & attr){
			this->dataAttributes.Add(attr);
		}

		HtmlDataAttribute & HtmlElement::GetDataAttribute(String & name){
			size_t len = 0;
			HtmlDataAttribute attr;

			len = this->dataAttributes.Count();

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

		std::string HtmlElement::ToString(){
			return std::string("System.Web.HtmlElement");
		}

		std::string HtmlElement::GetTypeString(){
			return std::string("HtmlElement");
		}

		/*
		HtmlElement & HtmlElement::operator=(HtmlElement & ele) {
			if(this != &ele) {
				this->accessKey = ele.accessKey;
				//this->children = ele.children;
				this->contentEditable = ele.contentEditable;
				this->contextMenu = ele.contextMenu;
				this->dataAttributes = ele.dataAttributes;
				this->dir = ele.dir;
				this->draggable = ele.draggable;
				this->dropzone = ele.dropzone;
				this->hidden = ele.hidden;
				this->html_part1 = ele.html_part1;
				this->html_part2 = ele.html_part2;
				this->id = ele.id;
				this->innerText = ele.innerText;
				this->lang = ele.lang;
				this->spellcheck = ele.spellcheck;
				this->style = ele.style;
				this->tabIndex = ele.tabIndex;
				this->title = ele.title;
				this->translate = ele.translate;
				this->_class = ele._class;
			}

			return *this;
		}
		
		HtmlElement & HtmlElement::operator=(HtmlElement && ele) {
			if(this != &ele) {
				*this = std::move(ele);
			}

			return *this;
		}
		*/
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
			for(size_t i = 0; i < this->dataAttributes.Count(); i++){
				HtmlDataAttribute attr = this->dataAttributes[i];

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