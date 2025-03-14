#pragma once

#include <vector> 

#include "Almond/Core.h"
#include "Layer.h"


namespace Almond
{
	class ALMOND_API LayerStack
	{

		public:
			LayerStack();
			virtual ~LayerStack();

			void PushLayer( Layer* layer );
			void PushOverlay( Layer* layer );
			void PopLayer( Layer* layer );
			void PopOverlay( Layer* layer );

			// wrapper for stack
			std::vector< Layer* >::iterator begin() { return m_Layers.begin(); }
			std::vector< Layer* >::iterator end() { return m_Layers.end(); }

		private:
			std::vector< Layer* > m_Layers;
			std::vector< Layer* >::iterator m_LayerInsert;

	};
}