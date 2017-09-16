#pragma once

#ifndef HTMLDATATABLE_H
#define HTMLDATATABLE_H

#include "Widget.h"
#include "Table.h"
#include "DNC\DataTable.h"
#include "DNC\Serializable.h"

namespace dnc {
	namespace Web {
		class HtmlDataTable : public Widget {
		public:
			HtmlDataTable();
			~HtmlDataTable();

			std::string ToString() override;
			std::string GetTypeString() override;

			void FromDataTable(Data::DataTable& table);
			template<typename T>
			void FromSerializable(Collections::Generic::List<T> list);

		};

		template<typename T>
		inline void HtmlDataTable::FromSerializable(Collections::Generic::List<T> list) {
			static_assert(std::is_base_of<Serializable, T>::value, "HtmlDataTable::FromSerializable - Template does not derive from Serializable.");

			size_t len = list.Count();

			if(len < 1) {
				return;
			}

			Tr headRow;
			Thead tHead;
			Tbody tBody;
			Table htable;

			// HEAD
			Serializable* seri = static_cast<Serializable*>(&list[0]);
			Collections::Generic::List<SerializableAttribute>& attributts = seri->attributes();
			size_t len_attr = attributts.Count();
			
			for(size_t i = 0; i < len_attr; i++) {
				Th headCell;

				auto attr = attributts[i];

				headCell.innerText(attr.AttributeName());

				headRow.AddElement(headCell);
			}
			tHead.AddElement(headRow);
			htable.AddElement(head);

			// ROWS
			for(size_t i = 0; i < len; i++) {
				T& t = list[i];

				Serializable* seri = static_cast<Serializable*>(&t);
				Collections::Generic::List<SerializableAttribute>& attributts = seri->attributes();
				
				Tr row;

				// CELLS
				for(size_t g = 0; g < len_attr; g++) {
					Td cell;

					auto attr = attributts[i];

					cell.innerText(attr.Member().ToString());

					row.AddElement(cell);
				}

				tBody.AddElement(row);
			}

			htable.AddElement(tBody);
			this->AddElement(htable);
		}

	}
}
#endif // !HTMLDATATABLE_H