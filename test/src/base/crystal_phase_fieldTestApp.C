//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "crystal_phase_fieldTestApp.h"
#include "crystal_phase_fieldApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
crystal_phase_fieldTestApp::validParams()
{
  InputParameters params = crystal_phase_fieldApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

crystal_phase_fieldTestApp::crystal_phase_fieldTestApp(InputParameters parameters) : MooseApp(parameters)
{
  crystal_phase_fieldTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

crystal_phase_fieldTestApp::~crystal_phase_fieldTestApp() {}

void
crystal_phase_fieldTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  crystal_phase_fieldApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"crystal_phase_fieldTestApp"});
    Registry::registerActionsTo(af, {"crystal_phase_fieldTestApp"});
  }
}

void
crystal_phase_fieldTestApp::registerApps()
{
  registerApp(crystal_phase_fieldApp);
  registerApp(crystal_phase_fieldTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
crystal_phase_fieldTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  crystal_phase_fieldTestApp::registerAll(f, af, s);
}
extern "C" void
crystal_phase_fieldTestApp__registerApps()
{
  crystal_phase_fieldTestApp::registerApps();
}
