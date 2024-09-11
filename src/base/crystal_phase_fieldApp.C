#include "crystal_phase_fieldApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
crystal_phase_fieldApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

crystal_phase_fieldApp::crystal_phase_fieldApp(InputParameters parameters) : MooseApp(parameters)
{
  crystal_phase_fieldApp::registerAll(_factory, _action_factory, _syntax);
}

crystal_phase_fieldApp::~crystal_phase_fieldApp() {}

void
crystal_phase_fieldApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<crystal_phase_fieldApp>(f, af, s);
  Registry::registerObjectsTo(f, {"crystal_phase_fieldApp"});
  Registry::registerActionsTo(af, {"crystal_phase_fieldApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
crystal_phase_fieldApp::registerApps()
{
  registerApp(crystal_phase_fieldApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
crystal_phase_fieldApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  crystal_phase_fieldApp::registerAll(f, af, s);
}
extern "C" void
crystal_phase_fieldApp__registerApps()
{
  crystal_phase_fieldApp::registerApps();
}
