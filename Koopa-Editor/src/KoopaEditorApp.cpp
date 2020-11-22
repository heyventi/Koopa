#include <Koopa.h>
#include <Koopa/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace kp {

	class KoopaEditor : public Application
	{
	public:
		KoopaEditor()
			: Application("Koopa Editor")
		{
			PushLayer(new EditorLayer());
		}

		~KoopaEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new KoopaEditor();
	}

}