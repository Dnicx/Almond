#include "aepch.h"
#include "LayerStack.h"

namespace Almond
{
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for( Layer* layer : m_Layers )
			delete layer;
	}

	void LayerStack::PushLayer( Layer* layer )
	{
		m_LayerInsert = m_Layers.insert( m_LayerInsert, layer );
	}

	void LayerStack::PushOverlay( Layer* layer )
	{
		m_Layers.push_back( layer );
	}

	void LayerStack::PopLayer( Layer* layer )
	{
		auto it = std::find( m_Layers.begin(), m_Layers.end(), layer );
		if ( it != m_Layers.end() )
		{
			m_Layers.erase( it );
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverlay( Layer* layer )
	{
		auto it = std::find( m_LayerInsert, m_Layers.end(), layer );
		if ( it != m_Layers.end() )
			m_Layers.erase( it );

	}
}